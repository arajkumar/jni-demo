#include <jni.h>
#include <iostream>

int main(int argc, char** argv) {
  JavaVMInitArgs args = {JNI_VERSION_10};
  jint ret = JNI_GetDefaultJavaVMInitArgs(&args);
  // std::cerr << "JNI_GetDefaultJavaVMInitArgs: ret:" << ret << " nOptions:" << args.nOptions<< "\n";

  JavaVM* jvm;
  JNIEnv* env;
  ret = JNI_CreateJavaVM(&jvm, (void**)&env, &args);
  // std::cerr << "JNI_CreateJavaVM: ret:" << ret << "\n";

  // System.out
  jclass system = env->FindClass("java/lang/System");
  jfieldID outID = env->GetStaticFieldID(system, "out", "Ljava/io/PrintStream;");
  jobject out = env->GetStaticObjectField(system, outID);

  // out.println
  jclass printStream = env->FindClass("java/io/PrintStream");
  jmethodID println = env->GetMethodID(printStream, "println", "(Ljava/lang/String;)V");
  env->CallVoidMethod(out, println, env->NewStringUTF("hello world"));
  // std::cerr << "Find System: ret:" << system << "\n";
  jvm->DestroyJavaVM();
  return 0;
}
