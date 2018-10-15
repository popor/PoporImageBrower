//
//  PoporImageBrowerBundle.h
//  PoporImageBrower
//
//  Created by apple on 2018/7/17.
//

#import <Foundation/Foundation.h>

#define PoporImageBrowerBundleImage(name) [PoporImageBrowerBundle imageName:name]

@interface PoporImageBrowerBundle : NSObject

// 设置默认图片
@property (nonatomic, strong) UIImage * placeholderImage;

+ (instancetype)share;

+ (UIImage *)imageName:(NSString *)name;

@end
