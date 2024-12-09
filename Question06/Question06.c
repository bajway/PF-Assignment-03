
/*In a cutting-edge agritech system for precision farming, a dynamic pointer-based architecture is
deployed to seamlessly manage interconnected data across fields, crops, weather, and smart
equipment. Each field is represented as a structure containing GPS coordinates, soil health metrics,
and moisture levels, alongside a pointer to a dynamically allocated array of crop structures. These
crop structures store critical details like crop type, growth stage, and expected yield while
maintaining pointers to weather forecast structures that provide hyper-local predictions for
temperature, rainfall, and wind patterns.
The field structure also includes a pointer to an equipment array, representing key farming tools
like autonomous tractors, irrigation systems, and drones. Each equipment structure tracks
operational status, fuel levels, and activity schedules, enabling synchronized field operations. In
addition, an array of sensor structures is linked to each field, capturing real-time data on soil
nutrients, pH levels, and pest activity, empowering farmers to make informed decisions.
To scale operations, fields are grouped into regional hubs, each represented by a structure with
pointers to arrays of fields. These hubs maintain aggregate data like yield predictions, resource
distribution, and emergency response plans. All regional hubs are connected to a central analytics
server through pointers, allowing AI algorithms to process massive datasets and generate real-time
insights on crop health, irrigation efficiency, and equipment optimization.
This system’s dynamic design ensures that every byte of memory is utilized efficiently, enabling
rapid scaling and adaptation to environmental conditions. By leveraging advanced pointer
structures, the agritech platform offers farmers a futuristic, data-driven farming experience that
maximizes yield, minimizes waste, and supports sustainable agricultural practices.*/


/*P.S//This wass a hellll of a questionnn structuress really got me thinkinggg*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definnig structures
typedef struct Crop{
    char cropType[50];
    char growthStage[50];
    double expectedYield;
    struct WeatherForecast *weatherForecast;
} Crop;
typedef struct WeatherForecast{
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;
typedef struct Equipment{
    char equipmentType[50];
    int operationalStatus; //1 and 0
    float fuelLevel;
    char activitySchedule[100];
} Equipment;
typedef struct Sensor{
    float soilNutrients;
    float pHLevel;
    int pestActivity; //1 for detected 0 for not detcted
} Sensor;
typedef struct Field{
    double gpsCoordinates[2]; //latitude/longitude
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int cropCount;
    Equipment *equipment;
    int equipmentCount;
    Sensor *sensors;
    int sensorCount;
} Field;
typedef struct RegionalHub{
    char regionName[50];
    Field *fields;
    int fieldCount;
    float aggregateYieldPrediction;
    float resourceDistribution;
    char emergencyResponsePlan[100];
} RegionalHub;
WeatherForecast *createWeatherForecast(float temp, float rain, float wind);
Crop *createCrops(int count);
Equipment *createEquipment(int count);
Sensor *createSensors(int count);
Field *createFields(int count);
RegionalHub *createRegionalHubs(int count);

int main(){
    WeatherForecast *forecast = createWeatherForecast(25.5, 12.3, 5.4);

    //creating crops
    int cropCount = 2;
    Crop *crops = createCrops(cropCount);
    strcpy(crops[0].cropType, "Wheat");
    strcpy(crops[0].growthStage, "Mature");
    crops[0].expectedYield = 1000.5;
    crops[0].weatherForecast = forecast;
    strcpy(crops[1].cropType, "Corn");
    strcpy(crops[1].growthStage, "Seedling");
    crops[1].expectedYield = 500.2;
    crops[1].weatherForecast = forecast;
    //creating equipement
    int equipmentCount = 2;
    Equipment *equipment = createEquipment(equipmentCount);
    strcpy(equipment[0].equipmentType, "Tractor");
    equipment[0].operationalStatus = 1;
    equipment[0].fuelLevel = 75.0;
    strcpy(equipment[0].activitySchedule, "Plowing at 10 AM");

    strcpy(equipment[1].equipmentType, "Drone");
    equipment[1].operationalStatus = 1;
    equipment[1].fuelLevel = 50.0;
    strcpy(equipment[1].activitySchedule, "Survey at 2 PM");

    //creating sensors
    int sensorCount = 3;
    Sensor *sensors = createSensors(sensorCount);
    sensors[0].soilNutrients = 8.5;
    sensors[0].pHLevel = 6.8;
    sensors[0].pestActivity = 0;

    sensors[1].soilNutrients = 7.0;
    sensors[1].pHLevel = 7.2;
    sensors[1].pestActivity = 1;

    sensors[2].soilNutrients = 9.1;
    sensors[2].pHLevel = 6.5;
    sensors[2].pestActivity = 0;

    //creating fields
    int fieldCount = 1;
    Field *fields = createFields(fieldCount);
    fields[0].gpsCoordinates[0] = 40.7128;
    fields[0].gpsCoordinates[1] = -74.0060;
    fields[0].soilHealth = 85.5;
    fields[0].moistureLevel = 60.0;
    fields[0].crops = crops;
    fields[0].cropCount = cropCount;
    fields[0].equipment = equipment;
    fields[0].equipmentCount = equipmentCount;
    fields[0].sensors = sensors;
    fields[0].sensorCount = sensorCount;

    //creating regionalhubs
    int regionalHubCount = 1;
    RegionalHub *hubs = createRegionalHubs(regionalHubCount);
    strcpy(hubs[0].regionName, "North Region");
    hubs[0].fields = fields;
    hubs[0].fieldCount = fieldCount;
    hubs[0].aggregateYieldPrediction = 1500.7;
    hubs[0].resourceDistribution = 3000.0;
    strcpy(hubs[0].emergencyResponsePlan, "Flood Response Plan A");

    printf("Regional Hub: %s\n", hubs[0].regionName);
    printf("Aggregate Yield Prediction: %.2f\n", hubs[0].aggregateYieldPrediction);
    printf("Resource Distribution: %.2f\n", hubs[0].resourceDistribution);
    printf("Emergency Plan: %s\n", hubs[0].emergencyResponsePlan);

    //free memory
    free(crops);
    free(equipment);
    free(sensors);
    free(fields);
    free(hubs);
    free(forecast);
    return 0;
}//End main
//funtions definations-
WeatherForecast *createWeatherForecast(float temp, float rain, float wind) {
    WeatherForecast *forecast = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    forecast->temperature = temp;
    forecast->rainfall = rain;
    forecast->windSpeed = wind;
    return forecast;
}

Crop *createCrops(int count){
    return (Crop *)malloc(sizeof(Crop) * count);
}

Equipment *createEquipment(int count){
    return (Equipment *)malloc(sizeof(Equipment) * count);
}

Sensor *createSensors(int count){
    return (Sensor *)malloc(sizeof(Sensor) * count);
}

Field *createFields(int count){
    return (Field *)malloc(sizeof(Field) * count);
}

RegionalHub *createRegionalHubs(int count){
    return (RegionalHub *)malloc(sizeof(RegionalHub) * count);
}
