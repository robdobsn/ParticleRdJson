// Example usage for RdJson library
// Rob Dobson 2017

#include "RdJson.h"

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

void setup() {

    Serial.begin(115200);
    delay(5000);
    Serial.println("Example usage of RdJson library");

    // Test JSON
    String jsonStr = "{\"maxSpeed\":12.2, \"message\":\"This is a test\", \"a\":[0,1,2,3], \"b\":{\"c\":42} }";

    // Double
    Serial.printlnf("Max speed %0.3f", RdJson::getDouble("maxSpeed", 0.0, jsonStr.c_str()));

    // String
    String messageStr = RdJson::getString("message", "", jsonStr.c_str());
    Serial.printlnf("Message %s", messageStr.c_str());

    // Array - by extracting string from JSON
    bool isValid = false;
    jsmnrtype_t objType = JSMNR_UNDEFINED;
    int objSize = 0;
    String arrayJson = RdJson::getString("a", "", isValid, objType, objSize, jsonStr.c_str());
    Serial.printlnf("Array %s valid %d, type %s, size %d", arrayJson.c_str(), isValid, RdJson::getObjTypeStr(objType), objSize);

    // Array elements - using a simplified form of XPATH - to get element 2 of the object a use a[2]
    long arrayElem = RdJson::getLong("a[2]", 0, jsonStr);
    Serial.printlnf("Array element [2] = %ld", arrayElem);

    // Extracting an element within a sub-object - use / separator like XPATH - also not that string will get any kind of object
    String subObjStr = RdJson::getString("b/c", "", jsonStr.c_str());
    Serial.printlnf("Sub-object string %s", subObjStr.c_str());
}

void loop() {
}
