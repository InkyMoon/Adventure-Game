// prints log messages to stdout.
#define LOGGING

// also prints log messages to 127.0.0.1:25555 for debugging without a terminal window or on android.
// hint: i use 'ncat -l -k -p 25555' on the same machine running the code to debug.
//#define NET_LOGGING