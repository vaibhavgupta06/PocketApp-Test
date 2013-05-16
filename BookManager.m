//
//  BookManager.m
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import "BookManager.h"

@implementation BookManager

-(void)fetchData
{
    BookService *service = [[BookService alloc] init];
    service.delegate = self;
    [service fetchDataWithURLWithString:kPocketAppBookURLString];
}

#pragma mark - Book Service Delegate Method

-(void)serviceDidFinishFetchingData:(NSArray *)jsonArray
{
    if (jsonArray) {
        _bookModelsArray = [BookModel arrayOfModelsFromDictionaries:jsonArray];
    }
    else{
        NSLog(@"jsonArray is nil in BookManager");
    }
    
    if (_bookModelsArray) {
        NSLog(@"Models Loaded Successfully");
        [_delegate managerDidFinishFetchingData:_bookModelsArray];
    }
    else {
        NSLog(@"Unable to load models in BookManager Class");
    }
}

@end
