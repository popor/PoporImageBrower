//
//  PoporImageBrowerBundle.m
//  PoporImageBrower
//
//  Created by apple on 2018/7/17.
//

#import "PoporImageBrowerBundle.h"

@implementation PoporImageBrowerBundle

+ (NSBundle *)bundle {
    static NSBundle *refreshBundle = nil;
    if (!refreshBundle) {
        refreshBundle = [NSBundle bundleWithPath:[[NSBundle bundleForClass:[PoporImageBrowerBundle class]] pathForResource:@"icon" ofType:@"bundle"]];
    }
    return refreshBundle;
}

// 怀疑下面的函数有问题.
+ (UIImage *)imageName:(NSString *)name {
    static int x = -1;
    if (x == -1) {
        x = (int )[UIScreen mainScreen].scale;
    }
    NSString * path = [self pathName:name x:x];
    if (!path) {
        switch (x) {
            case 2:
                path = [self pathName:name x:3];
                break;
            case 3:
                path = [self pathName:name x:2];
                break;
        }
    }
    if (path) {
        return [UIImage imageWithContentsOfFile:path];
    }else{
        return nil;
    }
}

+ (NSString *)pathName:(NSString *)name x:(int)x {
    return [[self bundle] pathForResource:[NSString stringWithFormat:@"%@@%ix", name, x] ofType:@"png"];
}

@end
