//
// Created by pradeep on 9/17/15.
//

#ifndef PHOENIX_PX_DLOG_H
#define PHOENIX_PX_DLOG_H

typedef struct dcheckpoint_t_{
    char var_name[20];
    int process_id;
    int version;
    void *data_ptr;

}dcheckpoint_t;

typedef struct dlog_t_{
    dcheckpoint_t *local_log;
    dcheckpoint_t *remote_log;
}dlog_t;


void dlog_init(dlog_t *dlog);
int dlog_write(dlog_t *dlog, listhead_t *lhead, checkpoint_type type);
dcheckpoint_t *dlog_read(dlog_t *log, char *var_name, int process_id);

#endif //PHOENIX_PX_DLOG_H


