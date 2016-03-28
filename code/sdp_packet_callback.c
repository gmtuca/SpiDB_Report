sdp_msg_t** msg_cpies = (sdp_msg_t**)sark_alloc(
			  QUEUE_SIZE, sizeof(sdp_msg_t*));
uint i = 0;

void sdp_packet_callback(register uint mailbox, uint port) {
    use(port);

    i = (i+1)%QUEUE_SIZE;
    register sdp_msg_t* m = msg_cpies[i];
    sark_word_cpy(m, (sdp_msg_t*)mailbox, sizeof(sdp_hdr_t)+256);
    spin1_msg_free((sdp_msg_t*)mailbox);

    // If there was space, add packet to the ring buffer
    if (circular_buffer_add(sdp_buffer, (uint32_t)m)) {
        if (!processing_events) {
            processing_events = true;
            if(!spin1_trigger_user_event(0, 0)){
                log_error("Unable to trigger user event.");
            }
        }
    }
    else{
        log_error("Unable to add SDP packet to circular buffer.");
    }
}
