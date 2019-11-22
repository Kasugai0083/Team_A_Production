#ifndef MONITOR_SCENE_H_
#define MONITOR_SCENE_H_

SceneId UpdateMonitorScene();

void DrawMonitorScene();

enum class MonitorID{
	ROOM_WORKSHOP,
	ROOM_STORE,
	ROOM_RECEPTION,
	ROOM_CHILD,
	CORRIDOR_RIGHT,
	CORRIDOR_LEFT,

	MAX_MONITOR_ID
};

#endif