typedef struct Response{
  id_t          id;
  spiDBcommand  cmd;

  bool          success;
  uint8_t       x;
  uint8_t       y;
  uint8_t       p;

  uchar         padding[3]; //word-alignment

  uchar         data[256];
} Response;
