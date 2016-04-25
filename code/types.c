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