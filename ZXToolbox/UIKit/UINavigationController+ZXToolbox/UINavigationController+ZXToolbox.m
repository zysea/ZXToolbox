//
// UINavigationController+ZXToolbox.m
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

#import "UINavigationController+ZXToolbox.h"

@implementation UINavigationController (ZXToolbox)

- (nullable UIViewController *)prevViewController {
    if (self.topViewController) {
        NSInteger index = [self.viewControllers indexOfObject:self.topViewController];
        if (index != NSNotFound && index > 0) {
            if (--index >= 0 && index < self.viewControllers.count) {
                return self.viewControllers[index];
            }
        }
    }
    return nil;
}

- (nullable UIViewController *)rootViewController {
    return [self.viewControllers firstObject];
}

- (NSArray<UIViewController *> *)popToViewControllerForClass:(Class)aClass animated:(BOOL)animated {
    for (NSInteger i = self.viewControllers.count - 1; i >= 0; --i) {
        UIViewController *vc = self.viewControllers[i];
        if (vc.class == aClass) {
            return [self popToViewController:vc animated:animated];
        }
    }
    return nil;
}

- (nullable NSArray<__kindof UIViewController *> *)removeViewControllersForClass:(Class)aClass limit:(NSInteger)limit {
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (UIViewController *vc in self.viewControllers) {
        if (vc.class == aClass) {
            [array addObject:vc];
        }
    }
    if (array.count > limit && limit > 0) {
        NSRange range = NSMakeRange(0, array.count - limit);
        [array removeObjectsInRange:range];
    }
    if (array.count > 0) {
        NSMutableArray *viewControllers = [self.viewControllers mutableCopy];
        [viewControllers removeObjectsInArray:array];
        self.viewControllers = [viewControllers copy];
    }
    return array.count > 0 ? [array copy] : nil;
}

@end
