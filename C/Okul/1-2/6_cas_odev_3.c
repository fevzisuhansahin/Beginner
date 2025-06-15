#include <stdio.h>
#include <stdlib.h>

typedef struct sensor{
    int id;
    int heat;
    int wet;
    int press;
}Sensor;

Sensor* setTheValue(int arr[]);
void printTheValue(Sensor *data);

int main(){
    int raw[3] = {
        0b01101111000111,   // Sensor 1
        0b11100100100101,   // Sensor 2
        0b10011111101011    // Sensor 3
    };

    Sensor* sensors = setTheValue(raw);
    printTheValue(sensors);
    free(sensors);
    return 0;
}

Sensor* setTheValue(int arr[]){
    int i;
    Sensor *data;
    data = (Sensor*)malloc(3*sizeof(Sensor));

    for(i=0;i<3;i++){
        data[i].id = (arr[i] >> 12) & 0b11;
        data[i].heat = (arr[i] >> 8) & 0b1111;
        data[i].wet = (arr[i] >> 5) & 0b111;
        data[i].press = arr[i] & 0b11111;
    }
    return data;
}

void printTheValue(Sensor *data){
    int i;
    for(i=0;i<3;i++){
        printf("Sensor%d -> id:%d\theat:%d\twet:%d\tpress:%d\n",(i+1),data[i].id,data[i].heat,data[i].wet,data[i].press);
    }
}