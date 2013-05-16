//
//  BookService.m
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

#import "BookService.h"

@implementation BookService

-(void)fetchDataWithURLString:(NSString *)stringURL
{
    dispatch_async(kBgQueue , ^{
        
        NSData *jsonData = [NSData dataWithContentsOfURL:[NSURL URLWithString:stringURL]];
        [self performSelectorOnMainThread:@selector(parseData:) withObject:jsonData waitUntilDone:YES];
        
    });

}

-(void) parseData:(NSData *) jsonData
{
    NSError *error;
    _booksArray = [NSJSONSerialization JSONObjectWithData:jsonData options:kNilOptions error:&error];
    
    if (error) {
        NSLog(@"Failed to fetch JSON Data");
        
    }
    else {
        [_delegate serviceDidFinishFetchingData:_booksArray];
    }
    
}

@end
