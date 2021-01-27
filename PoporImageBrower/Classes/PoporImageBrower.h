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

typedef UIImageView * _Nullable (^PoporImageBrowerIVBlock)   (PoporImageBrower * _Nonnull browerController, NSInteger index);
typedef UIImage *     _Nullable (^PoporImageBrowerImageBlock)(PoporImageBrower * _Nonnull browerController);
typedef void                    (^PoporImageBrowerVoidBlock) (PoporImageBrower * _Nonnull browerController, NSInteger index);

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

@property (nonatomic, readonly, copy) NSMutableArray<PoporImageBrowerEntity *> * myImageArray;
@property (nonatomic, weak          ) NSMutableArray<PoporImageBrowerEntity *> * weakImageArray;
/**
 小图的大小
 */
@property (nonatomic, readonly) CGSize normalImageViewSize;

// 关闭的时候, 是否恢复之前的方向, 默认为NO; 推荐使用APP自己控制的方向.
@property (nonatomic        ) BOOL autoResumePresentedVcOrientation;

/*
 注意: PoporImageBrower.modalPresentationStyle = UIModalPresentationCustom; 全局修改vc.modalPresentationStyle, 别忘了单独处理本接口.
 */
- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSMutableArray<PoporImageBrowerEntity *> * _Nullable)copyImageArray
                    presentVC:(UIViewController * _Nonnull)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

/*
 注意: PoporImageBrower.modalPresentationStyle = UIModalPresentationCustom; 全局修改vc.modalPresentationStyle, 别忘了单独处理本接口.
 */
// weakImageArray, 用于第二次开发,传递weakImageArray的时候,就不需要copyImageArray了
- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSMutableArray<PoporImageBrowerEntity *> * _Nullable)copyImageArray
               weakImageArray:(NSMutableArray<PoporImageBrowerEntity *> * _Nullable)weakImageArray
                    presentVC:(UIViewController * _Nonnull)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

/*
 注意: PoporImageBrower.modalPresentationStyle = UIModalPresentationCustom; 全局修改vc.modalPresentationStyle, 别忘了单独处理本接口.
 */
- (instancetype)initWithIndex:(NSInteger)index
               copyImageArray:(NSMutableArray<PoporImageBrowerEntity *> * _Nullable)copyImageArray
               weakImageArray:(NSMutableArray<PoporImageBrowerEntity *> * _Nullable)weakImageArray
                    presentVC:(UIViewController * _Nonnull)presentVC
             originImageBlock:(PoporImageBrowerIVBlock _Nonnull)originImageBlock
           willDisappearBlock:(PoporImageBrowerVoidBlock _Nullable)willDisappearBlock
               disappearBlock:(PoporImageBrowerVoidBlock _Nullable)disappearBlock
        placeholderImageBlock:(PoporImageBrowerImageBlock _Nullable)placeholderImageBlock;

// 没有放置到初始化函数中的参数.
@property (nonatomic) BOOL saveImageEnable; //是否禁止保存图片, 默认为YES
@property (nonatomic) BOOL showDownloadImageError;//是否显示下载图片出错信息, 默认为YES

/**
 显示图片浏览器
 注意: PoporImageBrower.modalPresentationStyle = UIModalPresentationCustom; 全局修改vc.modalPresentationStyle, 别忘了单独处理本接口.
 */
- (void)show;

- (void)showFinish:(void (^ _Nullable)(void))finish;

- (void)close;

// 不推荐使用的接口
- (instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder * _Nullable)aDecoder __unavailable;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new __unavailable;

@end

NS_ASSUME_NONNULL_END

