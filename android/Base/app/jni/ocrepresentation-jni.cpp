#include "ocstack-jni.h"

static const char* TAG = "OCREPRESENTATION-JNI";

JNIEXPORT jlong JNICALL OCRepresentationConstructor(JNIEnv *env, jobject jobj)
{
    OC::OCRepresentation *rep = new OC::OCRepresentation();
    jlong instptr = reinterpret_cast<jlong>(rep);
    return instptr;
}

JNIEXPORT jstring JNICALL getUri(JNIEnv *env, jobject jobj)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
    string uri = rep->getUri();
    __android_log_print(ANDROID_LOG_INFO, TAG, "getUri() URI : %s", uri.c_str());
    return env->NewStringUTF(uri.c_str());
}

JNIEXPORT jint JNICALL getValueInt(JNIEnv *env, jobject jobj, jstring jstr)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
	int val;
    rep->getValue(str, val);
    __android_log_print(ANDROID_LOG_INFO, TAG, "getValueInt() : %d", val);
    return((jint) val);
}


JNIEXPORT jboolean JNICALL getValueBool(JNIEnv *env, jobject jobj, jstring jstr)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
    bool val;
    rep->getValue(str, val);
    __android_log_print(ANDROID_LOG_INFO, TAG, "getValueBool() : %d", val);
    return((jboolean) val);
}

JNIEXPORT jstring JNICALL getValueString(JNIEnv *env, jobject jobj, jstring jstr)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
	string get_val;
    rep->getValue(str, get_val);

    __android_log_print(ANDROID_LOG_INFO, TAG, "getValueString() : %s", get_val.c_str());
    return env->NewStringUTF(get_val.c_str());
}

JNIEXPORT void JNICALL setValueInt(JNIEnv *env, jobject jobj, jstring jstr, jint jval)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
    rep->setValue(str, jval);
}

JNIEXPORT void JNICALL setValueBool(JNIEnv *env, jobject jobj, jstring jstr, jboolean jval)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
    rep->setValue(str, (bool) jval);
}

JNIEXPORT void JNICALL setValueString(JNIEnv *env, jobject jobj, jstring jstr, jstring jval)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);
	string val = env->GetStringUTFChars(jval,0);

    rep->setValue(str, val);
}

JNIEXPORT jboolean JNICALL hasAttribute(JNIEnv *env, jobject jobj, jstring jstr)
{
    OC::OCRepresentation *rep = getHandle<OC::OCRepresentation>(env, jobj);
	string str = env->GetStringUTFChars(jstr,0);

    return rep->hasAttribute(str);
}
