#ifndef SOUND_H_
#define SOUND_H_

//音を鳴らす
//同時再生可能
bool PlayStation(const char fileName[100], bool loop);

//使用した場合、情報を破棄する
//変数に値が入っていない場合、SoundEndするとエラーが発生する
void SoundEnd();

#endif