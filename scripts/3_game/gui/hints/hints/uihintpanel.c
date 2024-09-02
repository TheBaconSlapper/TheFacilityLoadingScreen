modded class UiHintPanel extends ScriptedWidgetEventHandler
{	
	// Const
	protected int 			m_SlideShowDelay			= 25000;											
	protected string 				m_RootPath			= "Gui/layouts/new_ui/hints/in_game_hints.layout";	
	protected const string 			m_DataPath			= "TheFacilityLoadingScreen/scripts/data/hints.json";						
	// Widgets
	protected Widget 				m_RootFrame;
	protected Widget 				m_SpacerFrame;
	protected ButtonWidget 			m_UiLeftButton;
	protected ButtonWidget 			m_UiRightButton;
	protected RichTextWidget		m_UiDescLabel;
	protected TextWidget			m_UiHeadlineLabel;
	protected ImageWidget 			m_UiHintImage;
	protected TextWidget 			m_UiPageingLabel;
	// Data		
	protected ref array<ref HintPage>	m_ContentList;
	protected int 					m_PageIndex = int.MIN;
	protected DayZGame				m_Game;
	protected bool					m_Initialized;
	protected Widget 				m_ParentWidget;
	protected int					m_PreviousRandomIndex = int.MIN;
	
	
	void UiHintPanel(Widget parent_widget)
	{		
		DayZGame game = DayZGame.Cast(GetGame());
		m_ParentWidget = parent_widget;
		Init(game);
	}
	
	void ~UiHintPanel()
	{
		StopSlideShow();
	
		if(m_RootFrame)
			m_RootFrame.Unlink();
	}

	
	void Init(DayZGame game)
	{
		if (m_Initialized)
			return;
		if (!game)
			return;
		m_Initialized = true;

		m_Game = game;
		
		LoadContentList();
		
		if (m_ContentList)	
		{
			
			BuildLayout(m_ParentWidget);
			
			RandomizePageIndex();
			
			PopulateLayout();
			
			StartSlideshow();			
		}
		else 
		{
			Print("ERROR: UiHintPanel - Could not create the hint panel. The data are missing!");
		}
	}
	
	
	protected void LoadContentList()
	{
		JsonFileLoader<array<ref HintPage>>.JsonLoadFile( m_DataPath, m_ContentList );
	}	
	
	
	protected void BuildLayout(Widget parent_widget)
	{
		
		m_RootFrame = m_Game.GetWorkspace().CreateWidgets( m_RootPath, parent_widget );
		
		if (m_RootFrame)
		{
			
			m_SpacerFrame		= m_RootFrame.FindAnyWidget("GridSpacerWidget1");		
			m_UiLeftButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("LeftButton"));		
			m_UiRightButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("RightButton"));
			m_UiHeadlineLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("HeadlineLabel"));	
			m_UiDescLabel		= RichTextWidget.Cast(m_RootFrame.FindAnyWidget("HintDescLabel"));
			m_UiHintImage		= ImageWidget.Cast(m_RootFrame.FindAnyWidget("HintImage"));
			m_UiPageingLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("PageInfoLabel"));
			
			m_RootFrame.SetHandler(this);
		}
	}
	
	
	protected void PopulateLayout()
	{
		if (m_RootFrame)
		{
			SetHintHeadline();
			SetHintDescription();
			SetHintImage();
			SetHintPaging();
		}
	}	
	
	protected void SetHintHeadline()
	{
		m_UiHeadlineLabel.SetText(m_ContentList.Get(m_PageIndex).GetHeadlineText());
	}
	protected void SetHintDescription()
	{
		#ifdef DEVELOPER

		#endif
		m_UiDescLabel.SetText(m_ContentList.Get(m_PageIndex).GetDescriptionText());
		m_UiDescLabel.Update();
		m_SpacerFrame.Update();
	}
	protected void SetHintImage()
	{
		string image_path = m_ContentList.Get(m_PageIndex).GetImagePath();
		
		
		if (image_path)
		{	
		
			m_UiHintImage.Show(true);
			
			m_UiHintImage.LoadImageFile(0, image_path);
		}
		else 
		{
			
			m_UiHintImage.Show(false);
		}
	}
	protected void SetHintPaging()
	{
		if (m_UiPageingLabel)
			m_UiPageingLabel.SetText(string.Format("%1 / %2", m_PageIndex + 1, m_ContentList.Count()));	
	}
	
	void ShowRandomPage()
	{
		RandomizePageIndex();
		PopulateLayout();
	}
	

	protected void RandomizePageIndex()
	{
		Math.Randomize(m_Game.GetTime());
		Math.RandomFloat01();
		while (m_PageIndex == m_PreviousRandomIndex)
			m_PageIndex = Math.RandomIntInclusive(0, m_ContentList.Count() - 1);
		m_PreviousRandomIndex = m_PageIndex;
		
	}
	
	protected void ShowNextPage()
	{
		
		if ( m_PageIndex < m_ContentList.Count() - 1 )
		{
			m_PageIndex++;
		}
		else 											
		{
			m_PageIndex = 0;
		}
		
	
		PopulateLayout();
	}	
	
	protected void ShowPreviousPage()
	{
		
		if ( m_PageIndex == 0 )
		{
			m_PageIndex = m_ContentList.Count() - 1;
		}
		else 
		{
			m_PageIndex--;
		
		}
		
		PopulateLayout();
	}

	
	protected void StartSlideshow()
	{
		m_Game.GetCallQueue(CALL_CATEGORY_GUI).CallLater(SlideshowThread, m_SlideShowDelay);
	}
	
	protected void SlideshowThread()
	{
		ShowNextPage();
	}
	
	protected void StopSlideShow()
	{
		m_Game.GetCallQueue(CALL_CATEGORY_GUI).Remove(SlideshowThread);
	}
	
	protected void RestartSlideShow()
	{
		StopSlideShow();
		StartSlideshow();
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT)
		{
			switch (w)
			{
				case m_UiLeftButton:
				{
					ShowPreviousPage();
					return true;
				}
				case m_UiRightButton:
				{	
					ShowNextPage();
					return true;
				}	
			}
		}
		return false;
	}
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_RootPath || w == m_UiLeftButton || w == m_UiRightButton)
		{
			StopSlideShow();
			return true;
		}
		return false;
	}
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_RootPath || w == m_UiLeftButton || w == m_UiRightButton)
		{
			RestartSlideShow();
			return true;
		}
		return false;
	}
}

modded class UiHintPanelLoading extends UiHintPanel
{
	override void Init(DayZGame game)
	{
		m_RootPath = "Hint/Scripts/3_Game/GUI/Layout/in_game_hints_load.layout"; 
		super.Init(game);
	}
}
