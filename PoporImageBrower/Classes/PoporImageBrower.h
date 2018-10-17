//
//  PoporImageBrower.h
//  Demo
//
//  Created by 周少文 on 16/8/20.
//  Copyright © 2016年 YiXi. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PoporImageBrowerEntity.h"
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

typedef UIImageView *(^PoporImageBrowerOriginImageBlock)(PoporImageBrower *browerController, NSInteger index);
typedef void         (^PoporImageBrowerDisappearBlock)(PoporImageBrower *browerController, NSInteger index);
typedef void         (^PoporImageBrowerSingleTapBlock)(PoporImageBrower *browerController, NSInteger index);
typedef UIImage *    (^PoporImageBrowerPlaceholderImageBlock)(PoporImageBrower *browerController);

@interface PoporImageBrower : UIViewController<UIViewControllerTransitioningDelegate,UIViewControllerAnimatedTransitioning>

@property (nonatomic, copy  ) PoporImageBrowerOriginImageBlock      originImageBlock;
@property (nonatomic, copy  ) PoporImageBrowerDisappearBlock        disappearBlock;
@property (nonatomic, copy  ) PoporImageBrowerPlaceholderImageBlock placeholderImageBlock;
@property (nonatomic, copy  ) PoporImageBrowerSingleTapBlock        singleTapBlock;

//保存是哪个控制器弹出的图片浏览器,解决self.presentingViewController在未present之前取到的值为nil的情况
@property (nonatomic,weak,readonly) UIViewController *presentVC;
/**
 显示状态
 */
@property (nonatomic,readonly) PoporImageBrowerStatus photoBrowerControllerStatus;

/**
 当前图片的索引
 */
@property (nonatomic,readonly) NSInteger index;

@property (nonatomic,readonly,copy) NSArray<PoporImageBrowerEntity *> * imageArray;
/**
 小图的大小
 */
@property (nonatomic,readonly) CGSize normalImageViewSize;

@property (nonatomic) BOOL saveImageEnable; //是否禁止保存图片, 默认为YES
@property (nonatomic) BOOL showDownloadImageError;//是否显示下载图片出错信息, 默认为YES

- (instancetype)initWithIndex:(NSInteger)index
                   imageArray:(NSArray<PoporImageBrowerEntity *> *)imageArray
                    presentVC:(UIViewController *)presentVC
             originImageBlock:(PoporImageBrowerOriginImageBlock _Nonnull)originImageBlock
               disappearBlock:(PoporImageBrowerDisappearBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerPlaceholderImageBlock _Nullable)placeholderImageBlock;

/**
 显示图片浏览器
 */
- (void)show;

- (void)close;

// 不推荐使用的接口
- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder __unavailable;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new __unavailable;

@end
