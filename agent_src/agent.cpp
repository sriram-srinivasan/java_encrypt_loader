#include "jvmti.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "net_malhar_Main.h"
#include "base64.h"

using namespace std;

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *jvm, char *options, void *reserved) {
    cout << "Secret agent started" << endl;
    return JNI_OK;
}

JNIEXPORT void JNICALL Java_net_malhar_Main_loadClasses(JNIEnv *env, jclass cl) {
    
    ifstream enc_precious_file("enc_precious_classes/net/malhar/Precious.eclass", ios::in | ios::ate);
    // read enc file contents into buffer
    std::stringstream buffer; 
    enc_precious_file.seekg(0);
    buffer << enc_precious_file.rdbuf();
    buffer.seekg(0);

    // 'decrypt' contents buffer. 
    std::vector<jbyte> precious_bytes = base64_decode(buffer.str());

    // define the class
    env->DefineClass("net/malhar/Precious", NULL /*loader*/, precious_bytes.data(), precious_bytes.size());
}