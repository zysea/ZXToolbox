//
// ZXLocationManager.h
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
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXLocationManager : NSObject <CLLocationManagerDelegate>
/// Location manager
@property (nonatomic, readonly) CLLocationManager *locationManager;
/// Current location
@property (nonatomic, readonly, nullable) CLLocation *location;
/// Represents placemark data for a geographic location.
@property (nonatomic, readonly, nullable) CLPlacemark *placemark;
/// Default is WhenInUse authorization
@property (nonatomic, assign) BOOL alwaysAuthorization;

/// Invoked when new locations are available.
@property (nonatomic, copy, nullable) void (^didUpdateLocation)(CLLocation *location, CLPlacemark *_Nullable placemark);

/**
 Request a single location update.
 */
- (void)requestLocation API_AVAILABLE(ios(9.0), macos(10.14));

/**
 Start updating locations.
 */
- (void)startUpdatingLocation;

/**
 Stop updating locations.
 */
- (void)stopUpdatingLocation;

@end

@interface CLPlacemark (ZXLocationManager)
/// The first administrative area of PRC
@property (nonatomic, readonly, nullable) NSString *province;
/// The second administrative area of PRC
@property (nonatomic, readonly, nullable) NSString *city;
/// The third administrative area of PRC
@property (nonatomic, readonly, nullable) NSString *district;
/// The street name
@property (nonatomic, readonly, nullable) NSString *street;
/// The street number
@property (nonatomic, readonly, nullable) NSString *streetNumber;
/// The formatted address
@property (nonatomic, readonly, nullable) NSString *address;

@end

NS_ASSUME_NONNULL_END
