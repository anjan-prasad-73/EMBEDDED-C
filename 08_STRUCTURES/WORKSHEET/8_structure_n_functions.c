#include <stdio.h>
#include <stdlib.h>

#define NUM_SENSORS 3
#define SAMPLE_COUNT 5
#define PAYLOAD_SIZE 10

// --- Nested Structures and Arrays ---
typedef struct {
    int hour, minute, second;
} Timestamp;

typedef struct {
    int sensorID;
    float value;
    Timestamp time; // nested structure
} SensorData;

typedef struct {
    int sensorID;
    float samples[SAMPLE_COUNT]; // buffer for multiple samples
} SensorBuffer;

typedef struct {
    int packetID;
    int length;
} Header;

typedef struct {
    float data[PAYLOAD_SIZE];
} Payload;

typedef struct {
    Header header;
    Payload payload;
} Packet;

// --- Structure for pointers and functions ---
typedef struct {
    int controlReg;
    int statusReg;
    int dataReg;
} Device;

typedef struct {
    int x, y;
} Point;

// Function to modify structure by value
void modifyByValue(Point p) {
    p.x += 10;
    p.y += 20;
    printf("Inside modifyByValue: x=%d, y=%d\n", p.x, p.y);
}

// Function to modify structure by pointer
void modifyByPointer(Point *p) {
    p->x += 10;
    p->y += 20;
    printf("Inside modifyByPointer: x=%d, y=%d\n", p->x, p->y);
}

// Function to return a structure
Point createPoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main() {
    printf("=== Structure Pointers and Memory Access ===\n");
    Device *devPtr = (Device *)malloc(sizeof(Device));
    if (!devPtr) return 1;
    devPtr->controlReg = 1;
    devPtr->statusReg = 0;
    devPtr->dataReg = 100;
    printf("Device: control=%d, status=%d, data=%d\n", 
           devPtr->controlReg, devPtr->statusReg, devPtr->dataReg);
    free(devPtr);

    printf("\n=== Nested Structures and Arrays ===\n");
    SensorData sensors[NUM_SENSORS];
    for(int i=0; i<NUM_SENSORS; i++){
        sensors[i].sensorID = i+1;
        sensors[i].value = 20 + i*0.5;
        sensors[i].time.hour = 10;
        sensors[i].time.minute = i*10;
        sensors[i].time.second = 0;
        printf("Sensor %d: %.2f at %02d:%02d:%02d\n",
               sensors[i].sensorID, sensors[i].value,
               sensors[i].time.hour, sensors[i].time.minute, sensors[i].time.second);
    }

    SensorBuffer buf;
    buf.sensorID = 1;
    for(int i=0;i<SAMPLE_COUNT;i++) buf.samples[i] = 20 + i*0.5;
    printf("Sensor %d samples: ", buf.sensorID);
    for(int i=0;i<SAMPLE_COUNT;i++) printf("%.2f ", buf.samples[i]);
    printf("\n");

    Packet pkt;
    pkt.header.packetID = 1;
    pkt.header.length = PAYLOAD_SIZE;
    for(int i=0;i<PAYLOAD_SIZE;i++) pkt.payload.data[i] = i*1.1;
    printf("Packet ID=%d, Length=%d, Payload: ", pkt.header.packetID, pkt.header.length);
    for(int i=0;i<PAYLOAD_SIZE;i++) printf("%.1f ", pkt.payload.data[i]);
    printf("\n");

    printf("\n=== Structures and Functions ===\n");
    Point pt = {5, 10};
    printf("Before modifyByValue: x=%d, y=%d\n", pt.x, pt.y);
    modifyByValue(pt);
    printf("After modifyByValue: x=%d, y=%d\n", pt.x, pt.y);

    printf("Before modifyByPointer: x=%d, y=%d\n", pt.x, pt.y);
    modifyByPointer(&pt);
    printf("After modifyByPointer: x=%d, y=%d\n", pt.x, pt.y);

    Point newPt = createPoint(7, 14);
    printf("Returned Point from createPoint: x=%d, y=%d\n", newPt.x, newPt.y);

    return 0;
}
