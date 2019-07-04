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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PoporImageBrowerStatus) {
    PoporImageBrowerUnShow,//未显示
    PoporImageBrowerWillShow,//将要显示出来
    PoporImageBrowerDidShow,//已经显示出来
    PoporImageBrowerWillHide,//将要隐藏
    PoporImageBrowerDidHide,//已经隐藏
};

@class PoporImageBrower;

extern NSTimeInterval const SWPhotoBrowerAnimationDuration;

typedef UIImageView *(^PoporImageBrowerIVBlock)(PoporImageBrower *browerController, NSInteger index);
typedef UIImage *    (^PoporImageBrowerImageBlock)(PoporImageBrower *browerController);
typedef void         (^PoporImageBrowerVoidBlock)(PoporImageBrower *browerController, NSInteger index);

@interface PoporImageBrower : UIViewController<UIViewControllerTransitioningDelegate,UIViewControllerAnimatedTransitioning>

@property (nonatomic, copy  ) PoporImageBrowerIVBlock    originImageBlock;
@property (nonatomic, copy  ) PoporImageBrowerImageBlock placeholderImageBlock;

@property (nonatomic, copy  ) PoporImageBrowerVoidBlock  willDisappearBlock;
@property (nonatomic, copy  ) PoporImageBrowerVoidBlock  disappearBlock;
@property (nonatomic, copy  ) PoporImageBrowerVoidBlock  singleTapBlock;
@property (nonatomic, copy  ) PoporImageBrowerVoidBlock  scrollBlock;

//保存是哪个控制器弹出的图片浏览器,解决self.presentingViewController在未present之前取到的值为nil的情况
@property (nonatomic, weak,readonly) UIViewController *presentVC;
/**
 显示状态
 */
@property (nonatomic, readonly) PoporImageBrowerStatus photoBrowerControllerStatus;

/**
 当前图片的索引
 */
@property (nonatomic, readonly) NSInteger index;

@property (nonatomic, readonly,copy) NSArray<PoporImageBrowerEntity *> * myImageArray;
@property (nonatomic, weak) NSArray<PoporImageBrowerEntity *> * weakImageArray;
/**
 小图的大小
 */
@property (nonatomic, readonly) CGSize normalImageViewSize;

- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSArray<PoporImageBrowerEntity *> *)copyImageArray
                    presentVC:(UIViewController *)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

// weakImageArray, 用于第二次开发,传递weakImageArray的时候,就不需要copyImageArray了
- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSArray<PoporImageBrowerEntity *> *)copyImageArray
               weakImageArray:(NSArray<PoporImageBrowerEntity *> *)weakImageArray
                    presentVC:(UIViewController *)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSArray<PoporImageBrowerEntity *> *)copyImageArray
               weakImageArray:(NSArray<PoporImageBrowerEntity *> *)weakImageArray
                    presentVC:(UIViewController *)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
           willDisappearBlock:(PoporImageBrowerVoidBlock _Nullable)willDisappearBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

// 没有放置到初始化函数中的参数.
@property (nonatomic) BOOL saveImageEnable; //是否禁止保存图片, 默认为YES
@property (nonatomic) BOOL showDownloadImageError;//是否显示下载图片出错信息, 默认为YES

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

NS_ASSUME_NONNULL_END

