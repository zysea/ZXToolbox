//
// ZXCommonDigest.h
// https://github.com/xinyzhao/ZXToolbox
//
// Copyright (c) 2019-2020 Zhao Xin
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

@protocol ZXCommonDigest <NSObject>

- (NSData *)MD2Data;
- (NSString *)MD2String;

- (NSData *)MD4Data;
- (NSString *)MD4String;

- (NSData *)MD5Data;
- (NSString *)MD5String;

- (NSData *)SHA1Data;
- (NSString *)SHA1String;

- (NSData *)SHA224Data;
- (NSString *)SHA224String;

- (NSData *)SHA256Data;
- (NSString *)SHA256String;

- (NSData *)SHA384Data;
- (NSString *)SHA384String;

- (NSData *)SHA512Data;
- (NSString *)SHA512String;

@end

@interface ZXCommonDigest : NSObject <ZXCommonDigest>
/// Size of read buffer, default is 4096 bytes
@property (nonatomic, assign) NSInteger bufferSize;

- (instancetype)initWithData:(NSData *)data;
- (instancetype)initWithString:(NSString *)string;
- (instancetype)initWithFileAtPath:(NSString *)path;
- (instancetype)initWithURL:(NSURL *)URL;

@end

@interface NSData (ZXCommonDigest) <ZXCommonDigest>

@end

@interface NSString (ZXCommonDigest)  <ZXCommonDigest>

@end
