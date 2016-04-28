typedef enum var_type  { UINT32=0, STRING } var_type;
typedef uint32_t id_t;
typedef uint32_t info_t;

typedef enum spiDBcommand {
    PUT = 0,
    PULL,

    CLEAR,

    PUT_REPLY,
    PULL_REPLY,

    CREATE_TABLE,
    INSERT_INTO,
    SELECT,
    SELECT_RESPONSE,

    PING
} spiDBcommand;

typedef struct Response{
  id_t          id;
  spiDBcommand  cmd;

  bool          success;
  uint8_t       x;
  uint8_t       y;
  uint8_t       p;

  uchar         pad[3];

  uchar         data[256];
} Response;
