#include "Audio.h"

bool AudioPlayer::Load(std::string alias_, std::string file_name_)
{
	if (m_SoundData.count(alias_) == 0) {
		m_SoundData.emplace(alias_, m_pSound->LoadWaveFile(file_name_));
		return true;
	}
	return false;
}

void AudioPlayer::Play(std::string alias_, int volume_, bool is_loop_)
{
	IDirectSoundBuffer8* psound = Find(alias_);
	// サウンドデータがなかった場合
	if (psound == nullptr) {
		return;
	}

	if (is_loop_) {
		psound->SetVolume(volume_);
		psound->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		psound->SetVolume(volume_);
		psound->Play(0, 0, 0);
		psound->SetCurrentPosition(0);
	}
}

void AudioPlayer::Stop(std::string alias_)
{
	IDirectSoundBuffer8* psound = Find(alias_);
	// サウンドデータがなかった場合
	if (psound == nullptr) {
		return;
	}
	psound->Stop();
}

void AudioPlayer::SetVolume(std::string alias_, int volume_)
{
	IDirectSoundBuffer8* psound = Find(alias_);
	// サウンドデータがなかった場合
	if (psound == nullptr) {
		return;
	}
	psound->SetVolume(volume_);
}

void AudioPlayer::Release(std::string alias_)
{
	IDirectSoundBuffer8* psound = Find(alias_);
	// サウンドデータがなかった場合
	if (psound == nullptr) {
		return;
	}
	if (psound) {
		psound->Release();
		psound = nullptr;
		m_SoundData.erase(alias_);
	}
}

IDirectSoundBuffer8* AudioPlayer::Find(std::string alias_)
{
	// サウンドデータをキーで検索
	auto data = m_SoundData.find(alias_);
	// サウンドデータが見つかった場合
	if (data != m_SoundData.end()) {
		return data->second;
	}
	// 見つからなかった場合
	return nullptr;
}

AudioPlayer::~AudioPlayer()
{
	if (m_SoundData.empty()) {
		// 要素の削除がすべて完了している場合はクリア
		m_SoundData.clear();
	}
	// 解放漏れがある場合
	for (auto data : m_SoundData) {
		IDirectSoundBuffer8* psound = data.second;
		if (psound == nullptr) {
			continue;
		}
		psound->Release();
		//m_SoundData.erase(data.first);	// ここでエラーが起こる
	}
	m_SoundData.clear();

	if (m_pSound) {
		delete m_pSound;
		m_pSound = nullptr;
	}

}