//
//  BookModel.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

//
// This web service returns an array of dictionaries i.e. Book Models which further has a key with name "author"
// The value for author key will be loaded into the Author Model
// The relationship here is "Book has an author"
//

#import "JSONModel.h"
#import "AuthorModel.h"

@protocol BookModel @end

@interface BookModel : JSONModel

@property(nonatomic,strong) NSString *bookId;
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSDate *dateCreated;
@property(nonatomic,strong) NSDate *lastUpdated;
@property(nonatomic,strong) AuthorModel *author;


@end
