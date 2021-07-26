/*
    This defines prototypes for data-related functions.
*/

struct data;

struct key;

struct dataMapping;

/*
    Read the given line and store the mapping from row to values.
*/
struct dataMapping *getDataMapping(char *header);

/*
    Read a line into the given key and data locations.
*/
void getData(char *row, struct dataMapping *mapping, struct key **key, 
    struct data **data);

/*
    Read a line as a key and return it.
*/
struct key *readKey(char *row, struct dataMapping *mapping);

/*
    Compare the two given keys. Returns -1 if the first key is less than the second,
    0 if they are a match and 1 if the second key is greater than the second.
*/
int compareKeys(struct key *firstKey, struct key *secondKey, struct dataMapping *mapping);
    
/*
    Frees the key and data in the given pair.
*/
void freeKeyPair(struct data **dataLoc, struct key **keyLoc, struct dataMapping *mapping);

/*
    Frees a standalone key.
*/
void freeKey(struct key **keyLoc, struct dataMapping *mapping);

/*
    Frees the given data mapping.
*/
void freeDataMapping(struct dataMapping **mapping);

/*
    Allocates space for a string representing the given
    key and returns it.
*/
char *getKeyString(struct dataMapping *mapping, struct key *key);

/*
    Allocates space for a string representing the given
    data and returns it.
*/
char *getDataString(struct dataMapping *mapping, struct data *data);
