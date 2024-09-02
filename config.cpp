class CfgPatches
{
	class TheFacilityLoadingScreen
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Consumables","DZ_Vehicles_Wheeled","DZ_Structures_Residential","DZ_Sounds_Effects","DZ_Sounds_Weapons"};
	};
};
class CfgMods
{
	class TheFacilityLoadingScreen
	{
	    dir = "TheFacilityLoadingScreen";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "TheFacilityLoadingScreen";
		logoSmall = "";
		logo = "";
		logoOver = "TheFacilityLoadingScreen";
		tooltip = "TheFacilityLoadingScreen";
		overview = "TheFacilityLoadingScreen";
	    credits = "JNG, Chubz";
	    author = "JNG, Chubz";
	    authorID = ;
	    version = "1.0";
	    extra = 0;
		
	    type = "mod";
		dependencies[]={"Mission","Game"}; 

	    class defs
	    {	
	    	class gameScriptModule
			{
				value="";
				files[]=
				{
					"TheFacilityLoadingScreen/scripts/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]={"TheFacilityLoadingScreen/scripts/5_Mission"};
			};			
        };
    };
};
class CfgSoundSets
{
	class FMusic_Menu_SoundSet
	{
		soundShaders[] = {"FMusic_Menu_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};
class CfgSoundShaders
{
	class FMusic_Menu_SoundShader
	{
		samples[] = {
			{"TheFacilityLoadingScreen\music\MainMenu.ogg", 1}
		};
		volume = 0.7;
	};
};
