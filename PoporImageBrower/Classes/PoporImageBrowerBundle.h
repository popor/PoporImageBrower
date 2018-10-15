//
//  PoporImageBrowerBundle.h
//  PoporImageBrower
//
//  Created by apple on 2018/7/17.
//

#import <Foundation/Foundation.h>

#define PoporImageBrowerBundleImage(name) [PoporImageBrowerBundle imageName:name]

@interface PoporImageBrowerBundle : NSObject

+ (UIImage *)imageName:(NSString *)name;

@end
