//
//  PoporImageBrowerViewController.m
//  PoporImageBrower
//
//  Created by popor on 10/11/2018.
//  Copyright (c) 2018 popor. All rights reserved.
//

#import "PoporImageBrowerViewController.h"
#import "MyCollectionViewCell.h"
#import <SDWebImage/UIImageView+WebCache.h>
#import <PoporImageBrower/SWPhotoBrowerController.h>

static NSString *const Cell = @"cell";

@interface PoporImageBrowerViewController ()<UICollectionViewDelegate, UICollectionViewDataSource, SWPhotoBrowerControllerDelegate>

@property (nonatomic, getter=isUseImage) BOOL useImage;
@property (nonatomic, strong) UICollectionView * collectionView;
@property (nonatomic, strong) NSArray * dataArray;

@property (nonatomic, strong) NSArray * smallImageArray;
@property (nonatomic, strong) NSArray * bigImageArray;

@end

@implementation PoporImageBrowerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.useImage = YES;
    self.dataArray = @[
                       @"http://ww2.sinaimg.cn/thumbnail/9ecab84ejw1emgd5nd6eaj20c80c8q4a.jpg",
                       @"http://ww2.sinaimg.cn/thumbnail/642beb18gw1ep3629gfm0g206o050b2a.gif",
                       @"http://ww4.sinaimg.cn/thumbnail/9e9cb0c9jw1ep7nlyu8waj20c80kptae.jpg",
                       @"http://ww3.sinaimg.cn/thumbnail/8e88b0c1gw1e9lpr1xydcj20gy0o9q6s.jpg",
                       @"http://ww2.sinaimg.cn/thumbnail/8e88b0c1gw1e9lpr2n1jjj20gy0o9tcc.jpg",
                       @"http://ww4.sinaimg.cn/thumbnail/8e88b0c1gw1e9lpr4nndfj20gy0o9q6i.jpg",
                       @"http://ww3.sinaimg.cn/thumbnail/8e88b0c1gw1e9lpr57tn9j20gy0obn0f.jpg",
                       @"http://ww2.sinaimg.cn/thumbnail/677febf5gw1erma104rhyj20k03dz16y.jpg",
                       @"http://ww4.sinaimg.cn/thumbnail/677febf5gw1erma1g5xd0j20k0esa7wj.jpg"
                       ];
    
    self.smallImageArray = @[
                             [UIImage imageNamed:@"9ecab84ejw1emgd5nd6eaj20c80c8q4a_s.jpg"],
                             [UIImage imageNamed:@"9e9cb0c9jw1ep7nlyu8waj20c80kptae_s.jpg"],
                             [UIImage imageNamed:@"8e88b0c1gw1e9lpr1xydcj20gy0o9q6s_s.jpg"],
                             [UIImage imageNamed:@"8e88b0c1gw1e9lpr2n1jjj20gy0o9tcc_s.jpg"],
                             [UIImage imageNamed:@"8e88b0c1gw1e9lpr4nndfj20gy0o9q6i_s.jpg"],
                             [UIImage imageNamed:@"8e88b0c1gw1e9lpr57tn9j20gy0obn0f_s.jpg"],
                             [UIImage imageNamed:@"677febf5gw1erma104rhyj20k03dz16y_s.jpg"],
                             ];
    self.bigImageArray = @[
                           [UIImage imageNamed:@"9ecab84ejw1emgd5nd6eaj20c80c8q4a_b.jpg"],
                           [UIImage imageNamed:@"9e9cb0c9jw1ep7nlyu8waj20c80kptae_b.jpg"],
                           [UIImage imageNamed:@"8e88b0c1gw1e9lpr1xydcj20gy0o9q6s_b.jpg"],
                           [UIImage imageNamed:@"8e88b0c1gw1e9lpr2n1jjj20gy0o9tcc_b.jpg"],
                           [UIImage imageNamed:@"8e88b0c1gw1e9lpr4nndfj20gy0o9q6i_b.jpg"],
                           [UIImage imageNamed:@"8e88b0c1gw1e9lpr57tn9j20gy0obn0f_b.jpg"],
                           [UIImage imageNamed:@"677febf5gw1erma104rhyj20k03dz16y_b.jpg"],
                           ];
    
    UICollectionViewFlowLayout *flow = [[UICollectionViewFlowLayout alloc] init];
    flow.itemSize = CGSizeMake(100, 100);
    flow.sectionInset = UIEdgeInsetsMake(20, 20, 20, 20);
    self.collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:flow];
    self.collectionView.delegate = self;
    self.collectionView.dataSource = self;
    self.collectionView.backgroundColor = [UIColor whiteColor];
    [self.collectionView registerClass:[MyCollectionViewCell class] forCellWithReuseIdentifier:Cell];
    [self.view addSubview:self.collectionView];
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    if (self.isUseImage) {
        return self.smallImageArray.count;
    }else{
        return self.dataArray.count;
    }
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    MyCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:Cell forIndexPath:indexPath];
    if (self.isUseImage) {
        cell.imgV.image = self.smallImageArray[indexPath.item];
    }else{
        [cell.imgV sd_setImageWithURL:[NSURL URLWithString:self.dataArray[indexPath.item]] placeholderImage:nil];
    }
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    if (self.isUseImage) {
        SWPhotoBrowerController *photoBrower = [[SWPhotoBrowerController alloc] initWithIndex:indexPath.item delegate:self normalImages:self.smallImageArray bigImages:self.bigImageArray browerPresentingViewController:self];
        // photoBrower.disablePhotoSave = YES;
        
        [photoBrower show];
        
    }else{
        NSMutableArray *normalImageUrls = [NSMutableArray arrayWithCapacity:0];
        NSMutableArray *bigImageUrls = [NSMutableArray arrayWithCapacity:0];
        [self.dataArray enumerateObjectsUsingBlock:^(NSString*  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [normalImageUrls addObject:[NSURL URLWithString:obj]];
            NSString *str = [obj stringByReplacingOccurrencesOfString:@"thumbnail" withString:@"bmiddle"];
            [bigImageUrls addObject:[NSURL URLWithString:str]];
        }];
        SWPhotoBrowerController *photoBrower = [[SWPhotoBrowerController alloc] initWithIndex:indexPath.item delegate:self normalImageUrls:[normalImageUrls copy] bigImageUrls:[bigImageUrls copy] browerPresentingViewController:self];
        // photoBrower.disablePhotoSave = YES;
        
        [photoBrower show];
    }
}

#pragma mark - SWPhotoBrowerControllerDelegate
- (UIImageView *)photoBrowerControllerOriginalImageView:(SWPhotoBrowerController *)browerController withIndex:(NSInteger)index {
    //cellForItemAtIndexPath:The cell object at the corresponding index path or nil if the cell is not visible or indexPath is out of range.
    MyCollectionViewCell *cell = (MyCollectionViewCell *)[self.collectionView cellForItemAtIndexPath:[NSIndexPath indexPathForItem:index inSection:0]];
    return cell.imgV;
}

- (void)photoBrowerControllerWillHide:(SWPhotoBrowerController *)browerController withIndex:(NSInteger)index {
    [self.collectionView scrollToItemAtIndexPath:[NSIndexPath indexPathForItem:index inSection:0] atScrollPosition:UICollectionViewScrollPositionNone animated:NO];
    //collectionView必须要layoutIfNeeded，否则cellForItemAtIndexPath,有可能获取到的是nil，
    [self.collectionView layoutIfNeeded];
}

- (BOOL)prefersStatusBarHidden {
    return NO;
}


@end
