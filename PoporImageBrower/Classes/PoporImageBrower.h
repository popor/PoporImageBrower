//
//  PoporImageBrower.h
//  Demo
//
//  Created by 周少文 on 16/8/20.
//  Copyright © 2016年 YiXi. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PoporImageEntity.h"
#import "PoporImageBrowerBundle.h"

typedef NS_ENUM(NSUInteger, PoporImageBrowerStatus) {
    PoporImageBrowerUnShow,//未显示
    PoporImageBrowerWillShow,//将要显示出来
    PoporImageBrowerDidShow,//已经显示出来
    PoporImageBrowerWillHide,//将要隐藏
    PoporImageBrowerDidHide,//已经隐藏
};

@class PoporImageBrower;

extern NSTimeInterval const SWPhotoBrowerAnimationDuration;

@protocol PoporImageBrowerDelegate <NSObject>

@required

/**
 从哪个原始的UIImageView显示放大动画

 @param browerController 图片浏览器
 @param index 当前图片索引
 @return 原始的UIImageView
 */
- (UIImageView *)photoBrowerControllerOriginalImageView:(PoporImageBrower *)browerController withIndex:(NSInteger)index;

@optional
/**
 图片浏览器即将执行消失动画
 
 @param browerController 图片浏览器
 @param index 当前图片索引
 */
- (void)photoBrowerControllerWillHide:(PoporImageBrower *)browerController withIndex:(NSInteger)index;
/**
 下载失败的占位图

 @param browerController 图片浏览器
 @return 占位图
 */
- (UIImage *)photoBrowerControllerPlaceholderImageForDownloadError:(PoporImageBrower *)browerController;

@end

@interface PoporImageBrower : UIViewController<UIViewControllerTransitioningDelegate,UIViewControllerAnimatedTransitioning>

//保存是哪个控制器弹出的图片浏览器,解决self.presentingViewController在未present之前取到的值为nil的情况
@property (nonatomic,weak,readonly) UIViewController *browerPresentingViewController;
/**
 显示状态
 */
@property (nonatomic,readonly) PoporImageBrowerStatus photoBrowerControllerStatus;

@property (nonatomic,weak) id<PoporImageBrowerDelegate> delegate;
/**
 当前图片的索引
 */
@property (nonatomic,readonly) NSInteger index;

@property (nonatomic,readonly,copy) NSArray<PoporImageEntity *> * imageArray;
/**
 小图的大小
 */
@property (nonatomic,readonly) CGSize normalImageViewSize;
/**
 是否禁止保存图片
 */
@property (nonatomic) BOOL disablePhotoSave;

- (instancetype)initWithIndex:(NSInteger)index delegate:(id<PoporImageBrowerDelegate>)delegate imageArray:(NSArray<PoporImageEntity *> *)imageArray presentingVC:(UIViewController *)presentingVC;

/**
 显示图片浏览器
 */
- (void)show;

// 不推荐使用的接口
- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder __unavailable;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new __unavailable;

@end
