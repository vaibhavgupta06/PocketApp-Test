//
//  BookModel.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import "JSONModel.h"
#import "AuthorModel.h"

@interface BookModel : JSONModel

@property(nonatomic,strong) NSString *className;
@property(nonatomic,strong) NSString *bookId;
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSDate *dateCreated;
@property(nonatomic,strong) NSDate *lastUpdated;
@property(nonatomic,strong) AuthorModel *author;


@end
