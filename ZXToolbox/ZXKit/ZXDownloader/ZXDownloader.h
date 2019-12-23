//
// ZXDownloader.h
// https://github.com/xinyzhao/ZXToolbox
//
// Copyright (c) 2019 Zhao Xin
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

#import "ZXDownloadTask.h"

NS_ASSUME_NONNULL_BEGIN

/// ZXDownloader
@interface ZXDownloader : NSObject

/// The default instance of ZXDownloader
+ (instancetype)defaultDownloader;

/// The background instacnce of ZXDownloader
+ (instancetype)backgroundDownloader;

/// Destination directory of download
@property (nonatomic, copy) NSString *downloadPath;

/// The maximum number of downloads that can execute at the same time, default is 0 which means no limit.
@property (nonatomic, assign) NSInteger maxConcurrentDownloadCount;

/// The current number of concurrent downloads
@property (nonatomic, readonly) NSInteger currentConcurrentDownloadCount;

/// Auto resume next download task when maxConcurrentDownloadCount > 0, default is false
@property (nonatomic, assign) BOOL autoResumeNextDownloadTask;

/// Enable to allow untrusted SSL certificates, default YES.
@property (nonatomic, assign) BOOL allowInvalidCertificates;

/// The credential that should be used for authentication.
@property (nonatomic, strong, nullable) NSURLCredential * credential;

/// If have download tasks in background, please set this block in
/// [UIApplicationDelegate.application:handleEventsForBackgroundURLSession:completionHandler:]
@property (nonatomic, copy) void (^backgroundCompletionHandler)(void);

/// Create or got exist download task with URL
/// @param URL The URL
- (ZXDownloadTask *)downloadTaskWithURL:(NSURL *)URL;

/// Get download task for URL
/// @param URL The URL
- (ZXDownloadTask *)downloadTaskForURL:(NSURL *)URL;

/// Suspend the task for URL
/// @param URL The URL
- (void)suspendTaskForURL:(NSURL *)URL;

/// Suspend the task
/// @param task task The task
- (void)suspendTask:(ZXDownloadTask *)task;

/// Suspend all tasks
- (void)suspendAllTasks;

/// Resume or start the task for URL
/// @param URL The URL
- (void)resumeTaskForURL:(NSURL *)URL;

/// Start/Resume the task
/// @param task The task
- (BOOL)resumeTask:(ZXDownloadTask *)task;

/// Resume or start all tasks
- (void)resumeAllTasks;

/// Cancel the task for URL
/// @param URL The URL
- (void)cancelTaskForURL:(NSURL *)URL;

/// Cancel the task
/// @param task The task
- (void)cancelTask:(ZXDownloadTask *)task;

/// Cancel all download tasks
- (void)cancelAllTasks;

@end

NS_ASSUME_NONNULL_END
