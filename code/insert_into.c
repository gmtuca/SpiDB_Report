typedef struct Entry{
    id_t        row_id;
    uchar       col_name[16];
    size_t      size;
    var_type    type;

    uchar       pad[3]; //padding for word alignment

    uchar       value[256];
} Entry;

typedef struct insertEntryQuery {
    spiDBcommand cmd;
    id_t         id;

    uchar        table_name[16];
    Entry        e;
} insertEntryQuery;
