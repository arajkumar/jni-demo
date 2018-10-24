#include "demo_Foo.h"

#include <iostream>

JNIEXPORT void JNICALL Java_demo_Foo_hello
  (JNIEnv* env, jclass, jstring jstr) {
  const char* c_str = env->GetStringUTFChars(jstr, JNI_FALSE);
  std::cout << "native:" << c_str << "\n";
}
