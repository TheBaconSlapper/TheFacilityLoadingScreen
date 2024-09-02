modded class LoadingScreen
{
    ref TStringArray RandomLoadingScreenArray = {
        "TheFacilityLoadingScreen\\data\\Loadingscreen.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen1.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen2.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen3.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen4.edds"};

    override void Show()
    {        
        string preel = RandomLoadingScreenArray.GetRandomElement();
        m_ImageWidgetBackground.LoadMaskTexture("LoadingScreens\\data\\ls_mask.paa");
        m_ImageWidgetBackground.LoadImageFile(0, preel);   
        m_ImageLogoMid.Show(false);
        m_ImageLogoCorner.Show(false);            
        m_ModdedWarning.Show(false); 
        
        Widget panel = m_WidgetRoot.FindAnyWidget("BottomPanel");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("hint_frame");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("hintIcon");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("LinesRightImage");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("LinesImageRight");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("LinesLeftImage");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("LinesImageLeft");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("HeadlineLabel");
        if (panel) panel.Show(false);

        panel = m_WidgetRoot.FindAnyWidget("HintDescLabel");
        if (panel) panel.Show(false);

        super.Show();
    }
}

modded class LoginTimeBase extends UIScriptedMenu
{
    ref TStringArray RandomLoadingScreenArray = {
        "TheFacilityLoadingScreen\\data\\Loadingscreen.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen1.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen2.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen3.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen4.edds"};

    override Widget Init()
    {
        layoutRoot = super.Init();
        
        return layoutRoot;
    }

    override void Show()
    {
        super.Show();
        if (layoutRoot)
        {
            string preel = RandomLoadingScreenArray.GetRandomElement();
            ImageWidget background = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, preel);  

            
            Widget panel = layoutRoot.FindAnyWidget("BottomPanel");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("hint_frame");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("hintIcon");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesRightImage");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesImageRight");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesLeftImage");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesImageLeft");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("HeadlineLabel");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("HintDescLabel");
            if (panel) panel.Show(false);
        }
    }
}

modded class LoginQueueBase extends UIScriptedMenu
{
    ref TStringArray RandomLoadingScreenArray = {
        "TheFacilityLoadingScreen\\data\\Loadingscreen.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen1.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen2.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen3.edds",
        "TheFacilityLoadingScreen\\data\\Loadingscreen4.edds"};

    override Widget Init()
    {
        layoutRoot = super.Init();
        
        return layoutRoot;
    }

    override void Show()
    {
        super.Show();
        if (layoutRoot)
        {
            string preel = RandomLoadingScreenArray.GetRandomElement();
            ImageWidget background = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, preel);  

           
            Widget panel = layoutRoot.FindAnyWidget("BottomPanel");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("hint_frame");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("hintIcon");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesRightImage");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesImageRight");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesLeftImage");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("LinesImageLeft");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("HeadlineLabel");
            if (panel) panel.Show(false);

            panel = layoutRoot.FindAnyWidget("HintDescLabel");
            if (panel) panel.Show(false);
        }
    }
}
