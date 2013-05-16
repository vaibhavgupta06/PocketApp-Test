//
//  BookManager.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#define kPocketAppBookURLString @"http://dev.pocketapp.co.uk:8080/PocketAppTestData-0.1/book/listAsJson"

#import <Foundation/Foundation.h>
#import "BookService.h"
#import "BookModel.h"
#import "AuthorModel.h"

@protocol BookManagerFetchDataDelegate <NSObject>

-(void)managerDidFinishFetchingData:(NSArray *)modelData;

@end

@interface BookManager : NSObject <BookServiceFetchDataDelegate>

@property(nonatomic,strong) NSArray *bookModelsArray;
@property(nonatomic,strong) id<BookManagerFetchDataDelegate> delegate;

-(void)fetchData;



@end
