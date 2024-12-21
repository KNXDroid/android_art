/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "jni.h"

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

extern "C" JNIEXPORT void JNICALL Java_Main_printPthreadName(
    [[maybe_unused]] JNIEnv* env, [[maybe_unused]] jclass klass) {
  constexpr size_t kBufSize = 20;  // Thread names are at most 16 characters.
  char name[kBufSize];
  int ret = pthread_getname_np(pthread_self(), name, kBufSize);
  if (ret == 0) {
    printf("%s\n", name);
  } else {
    fprintf(stderr, "pthread_getname_np failed: %s\n", strerror(ret));
  }
}
