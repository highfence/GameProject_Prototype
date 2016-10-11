# GameProject_Prototype

## !씬관리 프로토타입입니다.

업로드 / 다운로드 속도상 내부 plugin, tool폴더는 제외하였습니다.

빌드 이후의 커밋은 Cpp와 Resource만 업데이트 하겠습니다.



##Goal : 

![alt tag](https://cloud.githubusercontent.com/assets/20576399/19218331/fad52fe4-8e31-11e6-8613-42372f263c52.png)


##Details :

씬 구조는 위와 같습니다.
씬 변경에는 replaceScene과 pop/pushScene의 두 가지 방법을 사용하였습니다.

우선 replaceScene은 불러오려는 씬을 메모리에 완전히 적재한 뒤 화면에 올리므로 메모리의 효율성이 좋습니다.
예시로는 EndlingScene/DeadScene에서 ReturnToTitle 함수를 통하여 TitleScene으로 돌아오는 것을 볼 수 있습니다.

pop/pushScene은 스택 구조에 씬을 저장하는 방법입니다.
메모리 효율성을 replaceScene에 비해 좋지 않지만 push이후 pop을 하여 다시 씬으로 돌아갈 경우 그 씬의 상태가 저장된다는 장점이 있습니다.
필드에서 아이템 창을 열거나 할 경우 사용하면 좋을 것 같습니다.
예시로는 TitleScene에서 HighscoreScene과 AboutScene을 왔다갔다할 때 사용한 것을 볼 수 있습니다.


##부족한 점 :

우선 러프하게 하느라 코드 중복이 굉장히 많습니다.
우측 하단에 프로그램 종료버튼이 그 대표적인 예시인데요, 이 버튼을 만들기 위해 모든 씬에 같은 코드를 집어넣어야 했습니다.

이것을 해결하기 위해 어떠한 기본적인 기능들을 담은 기본 씬 클래스를 만들어 다른 씬들이 이것을 상속받게 해야하는지,
아니면 버튼 클래스를 따로 만들어 이 객체를 씬에서 포함하게 해야할지 잘 모르겠습니다.
감사합니다.


##Sounds :

사운드는 기본적으로 SimpleAudioEngine.h이라는 헤더 파일을 필요로 합니다. cocos2d-x에서 제공하는 여러가지 사운드 기능들이 들어있는 헤더입니다.
또한 pre-complied header에 using namespace CocosDenshion을 통하여 네임스페이스를 생략하였습니다.

StoryScene에 우선 배경음악을 출력해 보았습니다.
배경음악은 간단히
'''
SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM.mp3");
'''
와 같은 형식으로 출력할 수 있습니다.
또한 배경음악은 
'''
SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
'''
같은 함수를 통하여 쉽게 일시 정지/리플레이를 조작할 수 있습니다.

또한
'''
SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(float Volume);
// 배경음 볼륨지정<br>
float SimpleAudioEngine:: getInstance()->getBackgroundMusicVolume();
// 배경음 볼륨값 얻어오기 <br>
SimpleAudioEngine:: getInstance()->preloadBackgroundMusic(const char *pszFilePath);
// 배경음 미리 로딩해오기 <br>
bool SimpleAudioEngine:: getInstance()->isBackgroundMusicPlaying();
// 배경음 플레이 여부를 리턴받기. <br>
'''
같은 기능들을 제공합니다.


그 이후 PlayScene에 효과음을 출력해보았습니다.
'''
SimpleAudioEngine::getInstance()->playEffect("effect.wav", false);
'''
출력방법은 비슷하며 효과음은 효과음 고유의 int형 ID값을 리턴받는다는 점이 차이점입니다.
이 ID를 통하여 효과음을 제어할 수 있지만, 보통은 현재 출력되고 있는 모든 효과음을 한 번에 제어하는 경우가 많다고 합니다.

'''
SimpleAudioEngine::getInstance()->pauseAllEffects();
SimpleAudioEngine::getInstance()->resumeAllEffects();
'''
