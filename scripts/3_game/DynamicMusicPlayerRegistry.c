modded class DynamicMusicPlayerRegistry
{
    protected override void RegisterTracksMenu()
	{
		m_TracksMenu = new array<ref DynamicMusicTrackData>();

		RegisterTrackMenu("FMusic_Menu_Soundset");
		//RegisterTrackMenu("FMusic_Menu_SoundSet_2");
	}
}