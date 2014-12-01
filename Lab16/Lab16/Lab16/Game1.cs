using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace Lab16
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        // audio components
        AudioEngine audioEngine;
        WaveBank waveBank;
        SoundBank soundBank;
        
        //window size constants
        const int WINDOW_WIDTH = 584;
        const int WINDOW_HEIGHT = 438;

        Boolean mouseClickedButNotReleased = false;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            //makes mouse visible
            IsMouseVisible = true;

            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            //Load audio
            audioEngine = new AudioEngine(@"Content\CrossPlatformAudioProject.xgs");
            waveBank = new WaveBank(audioEngine, @"Content\Wave Bank.xwb");
            soundBank = new SoundBank(audioEngine, @"Content\Sound Bank.xsb");
            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            //code to find if mouse is in top left
            MouseState mouse = Mouse.GetState();

            if (mouse.LeftButton == ButtonState.Pressed && mouseClickedButNotReleased == false)
            {
                mouseClickedButNotReleased = true;
            }
            else if (mouseClickedButNotReleased == true && mouse.LeftButton == ButtonState.Released){
                mouseClickedButNotReleased = false;
                //play upperLeft sound - frog
                if ((Mouse.GetState().X < WINDOW_WIDTH / 2) && (Mouse.GetState().Y < WINDOW_HEIGHT / 2)){
                    soundBank.PlayCue("upperLeft");
                }

                //play upperRight sound - owl
                if ((Mouse.GetState().X > WINDOW_WIDTH / 2) && (Mouse.GetState().Y < WINDOW_HEIGHT / 2)){
                    soundBank.PlayCue("upperRight");
                }

                //play lowerLeft sound - pig
                if ((Mouse.GetState().X < WINDOW_WIDTH / 2) && (Mouse.GetState().Y > WINDOW_HEIGHT / 2)){
                    soundBank.PlayCue("lowerLeft");
                }

                //play lowerRight sound - wolf
                if ((Mouse.GetState().X > WINDOW_WIDTH / 2) && (Mouse.GetState().Y > WINDOW_HEIGHT / 2)){
                    soundBank.PlayCue("lowerRight");
                }

            }
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.White);
            base.Draw(gameTime);
        }
    }
}
