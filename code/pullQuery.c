typedef struct pullQuery{
  spiDBcommand    cmd;
  uint32_t        id;

  uint32_t        info;
  uchar           k[256];
} pullQuery;
