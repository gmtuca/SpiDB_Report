typedef struct Column {
    uchar       name[16];
    var_type    type;
    size_t      size;
} Column;

typedef struct Table {
    uchar       name[16];
    size_t      n_cols;
    size_t      row_size;
    size_t      current_n_rows;
    Column      cols[4];
} Table;

typedef struct createTableQuery { //CREATE TABLE
    spiDBcommand cmd;
    id_t         id;

    Table        table;
} createTableQuery;

typedef struct Entry{
    id_t        row_id;
    uchar       col_name[16];
    size_t      size;
    var_type    type;

    uchar       pad[3]; //padding for the value

    uchar       value[256];
} Entry;

typedef struct insertEntryQuery { //INSERT INTO
    spiDBcommand cmd;
    id_t         id;

    uchar        table_name[16];
    Entry        e;
} insertEntryQuery;

typedef enum {
    EQ = 0,   // =
    NE,       // != or <>
    GT,       // >
    GE,       // >=
    LT,       // <
    LE,       // <=
    BETWEEN,
    LIKE,
    IN
} Operator;

typedef enum {
    LITERAL_UINT32 = 0,
    LITERAL_STRING,
    COLUMN
} OperandType;

typedef struct Operand {
    OperandType type;
    uchar       value[64];
} Operand;

typedef struct Condition {
    Operand     left;
    Operator    op;
    Operand     right;
} Condition;

typedef struct selectResponse {
    spiDBcommand cmd;
    id_t         id;

    Table*       table;
    address_t    addr;

    uchar        n_cols;
    uchar        col_indices[MAX_NUMBER_OF_COLS];
} selectResponse;

typedef struct selectQuery { //SELECT FROM
    spiDBcommand cmd;
    id_t         id;

    uchar        table_name[16];
    uchar        col_names[MAX_NUMBER_OF_COLS][16];

    Condition    condition;
} selectQuery;
