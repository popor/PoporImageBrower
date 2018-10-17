//
//  PoporImageBrowerEntity.h
//  PoporImageBrowerEntity
//
//  Created by apple on 2018/10/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PoporImageBrowerEntity : NSObject

@property (nonatomic, strong) UIImage * smallImage;
@property (nonatomic, strong) UIImage * bigImage;

@property (nonatomic, strong) NSURL * smallImageUrl;
@property (nonatomic, strong) NSURL * bigImageUrl;

- (BOOL)isUseImage;

@end

NS_ASSUME_NONNULL_END
