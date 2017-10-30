## FZKBLE

##如何安装
step1:
podfile 添加
pod 'FZKBLE', '~> 1.0.0'
执行 pod install  即可自动安装并集成依赖库

step2:导入.h文件
import <FZKBLE/FZKBLE.h>



##如何使用

```objc
//1.初始化及连接
-(void)initAndConnect{

FZKTBluetoothInfoModel *ble = [[FZKTBluetoothInfoModel alloc] init];
ble.mac = @"247189d2d6b8";
ble.key = @"346161343338";
ble.bluetoothID = @"F67100";



//调用连接
[[FZKTBluetoothManager instanceShare] connection:ble];
[FZKTBluetoothManager instanceShare].delegate = self;

}


//2.根据标签查询状态
- (IBAction)queryStatus:(UIBarButtonItem *)sender {


NSArray* tags = @[[NSString stringWithFormat:@"%zd" ,SRBLEOperationInstruction_B301],
[NSString stringWithFormat:@"%zd" ,MILEAGE_B311],
[NSString stringWithFormat:@"%zd" ,LEFTOIL_B312],
[NSString stringWithFormat:@"%zd" ,LEFTELEC_B313]
];

[[FZKTBluetoothManager instanceShare] queryStatusByTags:tags callbakc:^(NSError *error, NSArray *items) {

NSArray *statusItems = [StatusItem mj_keyValuesArrayWithObjectArray:items];
NSLog(@"查询到状态 \n%@",statusItems);


FZKBLEStatus *status = [[FZKBLEStatus alloc] init];
[status initWithStatusArray:items];
NSLog(@"查询到状态 数组转为模型 \n%@",status.mj_keyValues);


UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"状态"
message:[NSString stringWithFormat:@"%@",status.mj_keyValues]
delegate:nil
cancelButtonTitle:@"关闭"
otherButtonTitles:nil, nil];

[alert show];


}];
}






//3.蓝牙设备连接状态
- (void)bleConnectStatus:(FZKBLEConnectStatus)state{



switch (state) {
case FZKBLEConnectSuccess:
//连接成功
break;

case FZKBLELoginSuccess:
//登录成功可以进行收发数据
break;

case FZKBLEDisconnected:
//断开连接
break;
default:
break;
}

}

//4.设备主动上报状态的代理方法(蓝牙设备连接成功时会主动查询一次状态并上报)
-(void)receiveOtherStatus:(NSArray *)items{

//    NSLog(@"收到状态变更%@",items);
FZKBLEStatus *status = [[FZKBLEStatus alloc] init];
[status initWithStatusArray:items];
NSLog(@"收到状态变更 数组转为模型 \n%@",status.mj_keyValues);

}




//5.发送控制指令
- (void)sendCommand:(SRBLEInstruction)command{

[[FZKTBluetoothManager instanceShare] sendCommand:command callback:^(NSError *error, id responseObject) {
if (error) {

[SVProgressHUD showErrorWithStatus:error.domain];

}else{

[SVProgressHUD showSuccessWithStatus:@"指令执行成功"];
}

}];


}




//6.不使用蓝牙时 断开连接
-(void)dealloc{

[FZKTBluetoothManager instanceShare].delegate = nil;
[[FZKTBluetoothManager instanceShare] disConnection];

}

```




