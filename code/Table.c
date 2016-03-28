typedef enum var_type  { UINT32=0, STRING } var_type;

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
