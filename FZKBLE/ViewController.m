//
//  ViewController.m
//  FZKBLE
//
//  Created by work on 04/09/2017.
//  Copyright © 2017 SONG. All rights reserved.
//

#import "ViewController.h"
#import <FZKBLE/FZKBLE.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[FZKTBluetoothManager instanceShare] connection:nil];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
