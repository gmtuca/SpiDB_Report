#define MULTIPLE_OF_4(n) (((n+3)/4)*4)
#define try(cond) do { if (!cond) return false; } while (0)

address_t append(address_t* address, void* data, size_t size_bytes){
    try(address && data && size_bytes);

    address_t old_addr = *address;

    sark_mem_cpy(*address, data, size_bytes);
    *address += (size_bytes+3) >> 2;

    return old_addr;
}

size_t put(address_t* addr, info_t info, void* k, void* v){

    size_t k_size = k_size_from_info(info);
    size_t v_size = v_size_from_info(info);

    try(k_size && v_size && k && v);

    append(addr, &info, sizeof(info_t));
    append(addr, k,     k_size);
    append(addr, v,     v_size);

    return sizeof(info_t) +
           MULTIPLE_OF_4(k_size) +
           MULTIPLE_OF_4(v_size);
}
