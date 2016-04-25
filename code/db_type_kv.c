typedef struct putQuery{
    spiDBcommand    cmd;
    id_t            id;

    info_t          info;
    uchar           k_v[256];
} putQuery;

typedef struct pullQuery{
    spiDBcommand    cmd;
    id_t            id;

    info_t          info;
    uchar           k[256];
} pullQuery;

typedef struct pullValue{
    var_type type;
    size_t   size;

    uchar    pad[3];//padding

    uchar    data[256];
} pullValue;

typedef struct pullValueResponse{
    spiDBcommand    cmd;
    id_t            id;

    uchar           pad[3];//padding

    pullValue       v;
} pullValueResponse;