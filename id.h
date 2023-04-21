#ifndef CPROJECT_ID_H
#define CPROJECT_ID_H
unsigned int global_id = 0;
typedef struct {
    unsigned int global_id;
}id;

unsigned int get_next_id(id);

#endif //CPROJECT_ID_H
