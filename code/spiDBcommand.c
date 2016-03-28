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
