//
//  PoporImageBrowerEntity.h
//  PoporImageBrowerEntity
//
//  Created by apple on 2018/10/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PoporImageBrowerEntity : NSObject

@property (nonatomic, strong) UIImage * normalImage;
@property (nonatomic, strong) UIImage * bigImage; // 假如只有一个图片,那么必须要设置大图

@property (nonatomic, strong) NSURL * normalImageUrl;
@property (nonatomic, strong) NSURL * bigImageUrl; // 假如只有一个图片,那么必须要设置大图

- (BOOL)isUseImage;

@end

NS_ASSUME_NONNULL_END
