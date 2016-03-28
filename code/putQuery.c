typedef struct putQuery{
  spiDBcommand    cmd;
  uint32_t        id;

  uint32_t        info;
  uchar           k_v[256];
} putQuery;
