/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LZ4CODEC_H_
#define LZ4CODEC_H_

#include "Compressions.h"
#include "BlockCodec.h"

namespace NativeTask {

class Lz4CompressStream : public BlockCompressStream {
public:
  Lz4CompressStream(OutputStream * stream, uint32_t bufferSizeHint);
protected:
  virtual uint64_t maxCompressedLength(uint64_t origLength);
  virtual void compressOneBlock(const void * buff, uint32_t length);
};

class Lz4DecompressStream : public BlockDecompressStream {
public:
  Lz4DecompressStream(InputStream * stream, uint32_t bufferSizeHint);
protected:
  virtual uint64_t maxCompressedLength(uint64_t origLength);
  virtual uint32_t decompressOneBlock(uint32_t compressedSize, void * buff, uint32_t length);
};

} // namespace NativeTask

#endif /* LZ4CODEC_H_ */
