//
//  PoporImageBrowerCell.h
//  Demo
//
//  Created by 周少文 on 16/8/20.
//  Copyright © 2016年 YiXi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PoporImageBrowerEntity.h"

NS_ASSUME_NONNULL_BEGIN

@class PoporImageBrower;

@interface PoporImageBrowerCell : UICollectionViewCell<UIGestureRecognizerDelegate>

@property (nonatomic, strong) UIScrollView     *scrollView;
@property (nonatomic, strong) UIImageView      *imagView;
@property (nonatomic, strong) NSURL            *bigImageUrl;
@property (nonatomic, strong) NSURL            *smallImageUrl;
@property (nonatomic, weak  ) PoporImageBrower *browerVC;

- (void)adjustImageViewWithImage:(UIImage *)image;

@end


NS_ASSUME_NONNULL_END

